console.log('hello');
console.log(1+2 + "뭐라고 했어?");

var dgram = require("dgram");
var udp_socket = dgram.createSocket("udp4");

udp_socket.on("message",function(msg,rinfo){
  console.log(rinfo.address);
  console.log(msg);
});

udp_socket.bind(3333);