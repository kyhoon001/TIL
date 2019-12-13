from flask import Flask, render_template,request
from decouple import config
import requests
from IPython import embed

app = Flask(__name__)


base = 'https://api.telegram.org'
token = config('TELEGRAM_BOT_TOKEN')
chat_id = config('CHAT_ID')
naver_client_id = config('NAVER_CLIENT_ID')
naver_client_secret = config('NAVER_CLIENT_SECRET')


@app.route('/')
def hello_world():
    return 'Hello, World!'

@app.route('/write')
def write():
    return render_template('write.html')

@app.route('/send')
def send():
    text = request.args.get('message')

    requests.get(f'{base}/bot{token}/sendMessage?chat_id={chat_id}&text={text}')
    return render_template('send.html')


#왜 안 되냐 근데 진짜 짜증나게
@app.route(f'/{token}', methods=['POST'])
def telegram():
    # print(request.get_json())
    from_telegram = request.get_json()
    # embed()
    if from_telegram.get('message') is not None:
        chat_id = from_telegram.get('message').get('from').get('id')
        text = from_telegram.get('message').get('text')
        url = f'{base}/bot{token}/sendMessage?chat_id={chat_id}&text={text}'
        # requests.get(url)



        if text[0:2] =='/ ':
            
            headers = {
                'X-Naver-Client-Id':naver_client_id,
                'X-Naver-Client-Secret':naver_client_secret
            }
            data = {'source':'ko', 'target':'en', 'text':text[2:]}
            papago_res = requests.post('https://openapi.naver.com/v1/papago/n2mt',headers=headers,data=data)


            text=papago_res.json().get('message').get('result').get('translatedText')

            requests.get(f'{base}/bot{token}/sendMessage?chat_id={chat_id}&text={text}')
        return '',200