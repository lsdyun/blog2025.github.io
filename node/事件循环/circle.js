/* setTimeout(() => {
    console.log('Timeout callback');
  }, 0);
  
  setImmediate(() => {
    console.log('Immediate callback');
  });
  
  console.log('Main thread execution'); */
setImmediate(() => console.log('Check 阶段回调'));
setTimeout(() => console.log('Timers 阶段回调'), 0);
Promise.resolve().then(() => console.log('Promise 微任务'));
process.nextTick(() => console.log('nextTick 微任务'));

// 输出顺序：
// nextTick 微任务 → Promise 微任务 → Timers 阶段回调 → Check 阶段回调  
