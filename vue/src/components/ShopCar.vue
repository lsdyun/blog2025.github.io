<template>
    <button @click="addItem">添加商品</button>
    <transition-group name="cart" tag="ul">
      <li
        v-for="item in cartItems"
        :key="item.id"
        class="cart-item"
      >
        {{ item.name }}
        <button @click="removeItem(item.id)">×</button>
      </li>
    </transition-group>
  </template>
  
  <script>
  import { defineComponent, ref } from 'vue'
  
  export default defineComponent({
    setup() {
      const cartItems = ref([]);
  
      const addItem = () => {
        const newItem = {
          id: Date.now(),
          name: `商品 ${cartItems.value.length + 1}`
        };
        cartItems.value.push(newItem);
      };
  
      const removeItem = (id) => {
        cartItems.value = cartItems.value.filter(item => item.id !== id);
      };
  
      return { cartItems, addItem, removeItem };
    }
  })
  </script>
  
  <style>
  .cart-item {
    transition: all 0.5s ease;
  }
  .cart-enter-from {
    opacity: 0;
    transform: translateX(30px);
  }
  .cart-leave-to {
    opacity: 0;
    transform: translateX(-30px);
  }
  .cart-leave-to {
    opacity: 0;
    transform: translateY(-20px);
  }
  .cart-leave-active {
    position: absolute;
  }
  </style>
  