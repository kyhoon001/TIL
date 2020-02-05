# vue.js - hello,world!

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
    <h1> {{ message }} </h1>
  </div>
  
  <div id = "hello">
    {{message}}
  </div>
  
  
  <div id = "world">
    {{message}}
  </div>
  
  <div id ="example">
    
    
  </div>
  
</body>
  
  <script>
    new Vue({
      el:'#hello',
      data:{
        message : 'hello vue world!'
      }
    });
    
    new Vue ({
      el:'#world',
      data:{
        message:'Vue.js World'
      }
    });
    
    
    var app = new Vue({
      el:'#app',    //el은  element를 의미함
      data : {
        message: 'Vue'
      },
      beforeCreate: function() {
        console.log("beforeCreate");
    
      },
      created:function() {
        console.log("created");
      },
      mounted: function() {
        console.log("mounted");
        this.message = 'Hello Vue!';
      },
      updated: function() {
        console.log("updated");
      }
    });
    
    
  </script>
</html>
```

