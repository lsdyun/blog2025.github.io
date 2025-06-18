/* fn main() {
    let v = vec![1, 2, 3, 4, 5];

    // 安全访问索引3
    let element = &v[3];  // 返回 &i32
    let element_option = v.get(100);  // 返回 Option<&i32>

    println!("Element: {}", element);
    
    // 正确处理Option
    match element_option {
        Some(value) => println!("Option value: {}", value),
        None => println!("Element does not exist"),
    }
} */

/* fn main(){
    let s1 = String::from("tic");
    let s2 = String::from("tac");

    // 方式1：s1 所有权被移动（后续不可用）
/*     let s3 = s1 + "-" + &s2;
    println!("{s1},{s2},{s3}"); */

    // 方式2：无所有权转移（推荐）
    let s4 = format!("{s1}-{s2}");
    println!("{s1},{s2},{s4}");
} */

/* fn main(){
    use std::collections::HashMap;

    let mut scores = HashMap::new();

    scores.insert(String::from("Blue"), 10);
    scores.insert(String::from("Yellow"), 50);

    let team_name = String::from("Blue");
    let score = scores.get(&team_name).copied().unwrap_or(0);
    println!("{score}");
} */

use std::collections::HashMap;

fn main(){
    let key = String::from("Color");
    let value = String::from("Blue");
    let mut map = HashMap::new();

    map.insert(key, value);  // key和value所有权转移
    // 此后不能再使用key和value
    println!("{key},{value}")
}