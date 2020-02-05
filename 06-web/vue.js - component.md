# vue.js - component

## 사용 예시

```html
<!DOCTYPE html>
<html>
<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width">
  <title>JS Bin</title>
  <script src = "https://unpkg.com/vue"></script> <!-- 스크립트 추가해주어야함 vue.js -->
</head>
<body>
  <div id="app">
    <my-global-component></my-global-component>
    <my-local-component></my-local-component>
  </div>
  
  <div id="app2">
    <my-global-component></my-global-component>
    <my-local-component></my-local-component>
  </div>
  
  <div id="app3">
    <my-component></my-component>
  </div>
  
</body>
  <script>
    //전역 component 등록
    Vue.component('my-global-component', {
      template:'<div> 전역 컴포넌트입니다.</div>'
    });
    
    var cmp = {
      template:'<div>지역 컴포넌트입니다.</div>'
    };
    
    new Vue({
      el: '#app',
      components: {
        'my-local-component': cmp
      }
    });
    
    new Vue({
      el: '#app2'
    });
    
    
    var app = new Vue({
      el:'#app3',    //el은  element를 의미함
      data : {
        message: 'Vue'
      },
      components: {
        "my-component":{
          template: "<div>A custom component!</div>"
        } 
      }
    });
    
    
  </script>
</html>
```



## 결과

```
전역 컴포넌트입니다.
지역 컴포넌트입니다.
전역 컴포넌트입니다.
A custom component!
```

