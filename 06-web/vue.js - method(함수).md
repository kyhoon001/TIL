# vue.js - method(함수)

```html
<!DOCTYPE html>
<html>
<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width">
  <title>Vue.js Sample</title>
  <script src = "https://unpkg.com/vue"></script> <!- 스크립트 추가해주어야함- -->
  
</head>
<body>
  <div id="app">
    {{reversedMessage()}}
  </div>
  
  
</body>
  
  <script>
    new Vue({
      el:'#app',
      data:{
        message : '메시지!!'
      },
      methods: {
        reversedMessage : function() {
          return this.message.split('').reverse().join('');
        }
      }
    });
    
    
  </script>
</html>
```



```
return this.message.split('')
 ==> 결과 : [ "메", "시", "지", "!", "!" ]
 
return this.message.split('').reverse()
 ==> 결과 : [ "!", "!", "지", "시", "메" ]
 
return this.message.split('').reverse().join('');
 ==> 결과 : !!지시메
```

