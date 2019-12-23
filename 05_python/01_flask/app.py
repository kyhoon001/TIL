from flask import Flask, render_template
from datetime import datetime
import random
app = Flask(__name__)

@app.route('/')
def hello():
    return 'Hello World'


@app.route('/t4ir')
def t4ir():
    return 'This is T4IR'

@app.route('/dday')
def dday():
    today = datetime.now()
    end = datetime(2020,4,21)
    td = end - today
    return f'{td.days}일 남았습니다.'

@app.route('/html')
def html() :
    return '<h1> this is html h1 tag!</h1>'



@app.route('/html_line')
def html_line():
    return """
    <h1> 여러줄을 보내봅시다.</h1>
    <ul>
        <li>1번</li>
        <li>2번</li>
    </ul>
    """


@app.route('/greeting/<name>')
def greeting(name):
    return f'반갑습니다! {name}님!'

@app.route('/cube/<int:number>')
def cube(number):
    return f'{number}의 3제곱 {number **3}'


@app.route('/lunch/<int:people>')
def lunch(people):
    menu = {'짜장면','찜뽕','볶음밥','고추잡채밥','개밥'}
    order = random.sample(menu,people)
    return str(order)





@app.route('/ssafy')
def ssafy():
    return 'SSAFY'


if __name__=='__main__':
    app.run(debug=True)