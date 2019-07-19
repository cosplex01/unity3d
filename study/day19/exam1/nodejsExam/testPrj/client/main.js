import '../lib/collection'
import {Meteor}from 'meteor/meteor';
import './main.html'

let hMsgLog;

Meteor.startup(function() {
  hMsgLog = Meteor.subscribe('msglog/list');
});

template.main.helpers({
  "getMsgLogList":function(){
    return MsgLog.find({})
  }
});
Template.main.events({
  'clicik .input-msg button'(evt,instance){
     console.log (instance.find('.input-msg input').value);
     Meteor.call('msgLog/add',
     {
       msg: instance.find('.input-msg input').value
     })
  }
});