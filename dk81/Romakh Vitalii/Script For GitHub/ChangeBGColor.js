// ==UserScript==
// @name         GitHub Background color changer
// @namespace    http://tampermonkey.net/
// @version      0.1
// @description  Make GitHub colorful!
// @author       BeHappy
// @match        https://github.com/*
// @grant        none
// ==/UserScript==

(function() {
    'use strict';
    ChangeColor("*");


    function ChangeColor(elements){
     var nodelist = document.querySelectorAll(elements);
     nodelist.forEach(function(item, i, nodelist) {
      item.style.backgroundColor = RandomColor();
     });
    }

    function RandomColor(){
    var red = Math.random() * (256 - 0) + 0;
      var green = Math.random() * (256 - 0) + 0;
      var blue = Math.random() * (256 - 0) + 0;
      var color = "rgb("+ red + "," + green + "," + blue + ")";
      return color;
    }
})();
