var d = new Date();
var d2;
var d3 = new Date();
//.getFullYear() -> 현재 년도
//getmonth() => 월 0~11
// date -> 일
// day 0~ 6 요일
// new Date
// 배열의 [0]은 어제 [1] 부터 오늘 7주잂치
// 날씨 = condition 총 네 개로 분류 (비 바람 해 구름)
var w = ['Rain','Windy','Sunny','Cloudy','Snowy'];
var s = ['Sun','Mon','Tue','Wed','Thu','Fri','Sat']
var m = ['need plus 1','Jan','Feb','Mar','Apr','May','June','July','Aug','Sep','Ouc','Nov','Dec'];
var condition = 
['https://3.bp.blogspot.com/-MmxJ6Uh54oI/WJvv5Bb78LI/AAAAAAAAAmU/Oil9g1JyNigPjckrftHQpxZIWOJihqNuwCLcB/s1600/fghjk.gif',
'https://i.kinja-img.com/gawker-media/image/upload/s--r13rwI0Y--/c_scale,fl_progressive,q_80,w_800/glonsn6uektlti9fmpiz.gif',
'https://giant.gfycat.com/TimelyWarmheartedAnole.gif',
'https://www.adventurebikerider.com/wp-content/uploads/2017/10/tumblr_o27c7fByaO1tchrkco1_500.gif',
'https://i.giphy.com/media/dAyD6PWoQRs40/giphy.gif'

]
Vue.component('weather-item', {
    props: ['weather'],
    methods: { td: 
        function() {
            var main_day = document.getElementById("main_day");
            var main_FullDay = document.getElementById("main_FullDay");
            var main_degree = document.getElementById( "main_degree");
            var main_weather = document.getElementById( "main_weather");
            var bg = document.getElementById("bg");
            main_day.innerHTML = this.weather.day;
            main_FullDay.innerHTML = this.weather.date +" " +  m[this.weather.month] + " " +this.weather.year;
            main_degree.innerHTML = this.weather.degree;
            main_weather.innerHTML = w[this.weather.weather];

    console.log(this.weather.day);
    bg.style.backgroundImage='url(' + condition[this.weather.weather] + ")";
}
    },
    template: `<div class="weakly-weather-item todaycolor" v-on:click="td()">
    <p class="mb-1" style="font-size:140%"> {{weather.day}} </p> <i class="mdi mdi-weather-hail"></i>
    <p class="mb-0" style="font-size:120%"> {{weather.degree}}° </p>
</div>`
})














var a= new Vue({
    el:'#wd',
    data : {
        weatherlist: [
        ]

    }
})
if(d.getDate() == 1) {
    d2 = new Date(d.getFullYear(),d.getMonth(),0);
}
else {
    d2 = new Date(d.getFullYear(),d.getMonth(),d.getDate()-1);
}
a.weatherlist.push(
    {year: d2.getFullYear(),
    month: d2.getMonth()+1,
    date: d2.getDate(),
    day: s[d2.getDay()],
    weather: Math.floor(Math.random()*5),
    degree: Math.floor(Math.random()*18) + 10
    });
a.weatherlist.push(
    {year: d.getFullYear(),
    month: d.getMonth()+1,
    date: d.getDate(),
    day: s[d.getDay()],
    weather: Math.floor(Math.random()*5),
    degree: Math.floor(Math.random()*18) + 10
    });

console.log(a.weatherlist);
for(var i = 0; i<5; i++) {
    d2 = new Date(d3.getFullYear(),d3.getMonth(),d3.getDate()+1);
    a.weatherlist.push(
        {year: d2.getFullYear(),
        month: d2.getMonth()+1,
        date: d2.getDate(),
        day: s[d2.getDay()],
        weather: Math.floor(Math.random()*5),
        degree: Math.floor(Math.random()*18) + 10
        });
    d3 = d2;
}
