from flask import Flask, render_template,request
from decouple import config
import requests
app = Flask(__name__)


base = 'https://api.telegram.org'
token = config('TELEGRAM_BOT_TOKEN')
chat_id = config('CHAT_ID')
text = 'hello'


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

@app.route(f'/{token}', methods=['POST'])
def telegram():
    print(request.get_json())
    from_telegram = request.get_json()

    if from_telegram.get('message') is not None:
        chat_id = from_telegram.get('message').get('from').get('id')
        text = from_telegram('message').get('text')
        request.get(f'{base}/bot{token}/sendMessage?chat_id={chat_id}&text={text}')
        requests.get(url)
    return '',200