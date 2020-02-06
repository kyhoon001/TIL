# vue.js - computed, watch

- computed

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
      {{reversedMessage}}
    </div>
    
    
  </body>
    
    <script>
      var vm = new Vue({
        el:'#app',
        data:{
          message : '메시지!!'
        },
        computed: {
          reversedMessage : function() {
            return this.message.split('').reverse().join('');
          }
        }
      });
      
      
    </script>
  </html>
  ```

  - computed의 경우 함수가 아니므로 body부분에 ()가 필요없다.



- watch

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
    {{message}}
  </div>
  
  
</body>
  
  <script>
    var vm = new Vue({
      el:'#app',
      data:{
        message : '메시지!!'
      },
      watch: {
        message : function(data) {
          console.log('데이터가 갱신되었습니다: ',data);
        }
      }
    });
    
    
  </script>
</html>
```

- console에서 vm.message = "asd" 등으로 값을 바꿔줄 경우 watch에 해당하는 부분이 실행

