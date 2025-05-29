<template>
    <div class="home">
      <shop-car></shop-car>
    </div>
  </template>
  
  <script>
  // @ is an alias to /src
  
  import ShopCar from '@/components/ShopCar.vue'
  
  export default {
    name: ['ShopCar'],
    components: {
      ShopCar
    }
  }
  </script>
  