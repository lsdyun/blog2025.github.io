use std::io;
use rand::Rng;
use std::cmp::Ordering;

fn main() {
    println!("猜数字！");

    let secret_number = rand::thread_rng().gen_range(1..=100);

    println!("生成的数字为：{secret_number}");

    loop {
        println!("请输入你猜的数字：");

        let mut guess = String::new();
    
        io::stdin()
            .read_line(&mut guess)
            .expect("读错了");
    
        //将guess从String转化为Integer,同时增加输入值是否为数字的判定
        let guess: u32 = match guess.trim().parse() {
            Ok(num) =>num,
            Err(_) => {
                println!("请输入数字!!!");
                continue;
            }
        };

        //println!("你猜对了:{guess}");
        println!("你猜的数字为：{guess}");
        match guess.cmp(&secret_number){
            Ordering::Less => println!("小一些"),
            Ordering::Greater => println!("大一些"),
            Ordering::Equal => {
                println!("猜对了！");
                break;
            }
        }
    }
}