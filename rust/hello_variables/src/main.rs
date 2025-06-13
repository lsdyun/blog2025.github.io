/* fn main() {
    let mut x = 5;
    println!("The value of x is: {x}");
    x = 6;
    println!("The value of x is: {x}");
} */

/* fn main() {
    let x = 5;

    let x = x + 1;

    {
        let x = x * 2;
        println!("The value of x in the inner scope is: {x}");
    }

    println!("The value of x is: {x}");
} */

/* fn main() {
    let tup: (i32, f64, u8) = (500, 6.4, 1);
    let (x, y, z) = tup;
    println!("The value of y is: {y}");
} */

/* fn main() {
    let tup: (i32, f64, u8) = (500, 6.4, 1);
    //使用点号（.）
    let one = tup.0;
    println!("The value of y is: {one}");
} */
/* 
fn five() -> i32 {
    5
}

fn main() {
    let x = five();

    println!("The value of x is: {x}");
} */

/* fn main() {
    let condition = true;

    let number = if condition { 5 } else { "six" };

    println!("The value of number is: {number}");
} */

/* fn main() {
    loop {
        println!("again!");
    }
} */

/* fn main() {
    let mut count = 0;
    'counting_up: loop {
        println!("count = {count}");
        let mut remaining = 10;

        loop {
            println!("remaining = {remaining}");
            if remaining == 9 {
                break;
            }
            if count == 2 {
                break 'counting_up;
            }
            remaining -= 1;
        }

        count += 1;
    }
    println!("End count = {count}");
} */

/* fn main() {
    for number in (1..4).rev() {
        println!("{number}!");
    }
    println!("LIFTOFF!!!");
} */


/* fn celsius_to_fahrenheit(c: f64) -> f64 {
    (c * 9.0 / 5.0) + 32.0
}

fn fahrenheit_to_celsius(f: f64) -> f64 {
    (f - 32.0) * 5.0 / 9.0
}

fn main() {
    let celsius = 25.0;
    let fahrenheit = celsius_to_fahrenheit(celsius);
    println!("{}°C = {}°F", celsius, fahrenheit);

    let fahrenheit = 77.0;
    let celsius = fahrenheit_to_celsius(fahrenheit);
    println!("{}°F = {}°C", fahrenheit, celsius);
} */

// 递归实现（时间复杂度O(2^n)）
/* fn fib_recursive(n: u32) -> u64 {
    match n {
        0 => 0,
        1 => 1,
        _ => fib_recursive(n-1) + fib_recursive(n-2)
    }
}

// 迭代实现（时间复杂度O(n)）
fn fib_iterative(n: u32) -> u64 {
    let (mut a, mut b) = (0, 1);
    for _ in 0..n {
        let tmp = a;
        a = b;
        b = tmp + b;
    }
    a
}

fn main() {
    let n = 3;
    println!("递归: fib({}) = {}", n, fib_recursive(n));
    println!("迭代: fib({}) = {}", n, fib_iterative(n));
} */


fn main() {
    let gifts = [
        "a partridge in a pear tree",
        "two turtle doves",
        "three french hens",
        "four calling birds",
        "five golden rings",
        "six geese a-laying",
        "seven swans a-swimming",
        "eight maids a-milking",
        "nine ladies dancing",
        "ten lords a-leaping",
        "eleven pipers piping",
        "twelve drummers drumming"
    ];

    for day in 1..=12 {
        println!("\nOn the {} day of Christmas", ordinal(day));
        println!("my true love gave to me:");
        
        for i in (0..day).rev() {
            if day > 1 && i == 0 {
                print!("and ");
            }
            println!("{}", gifts[i]);
        }
    }
}

fn ordinal(n: usize) -> String {
    match n {
        1 => "first".to_string(),
        2 => "second".to_string(),
        3 => "third".to_string(),
        4 => "fourth".to_string(),
        5 => "fifth".to_string(),
        6 => "sixth".to_string(),
        7 => "seventh".to_string(),
        8 => "eighth".to_string(),
        9 => "ninth".to_string(),
        10 => "tenth".to_string(),
        11 => "eleventh".to_string(),
        12 => "twelfth".to_string(),
        _ => n.to_string()
    }
}
