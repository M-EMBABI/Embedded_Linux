use std::net::{TcpListener, TcpStream};
use std::io::{Read, Write};
use std::thread;

fn handle_client(mut stream: TcpStream) {
    let mut buffer = [0; 512];
    loop {
        match stream.read(&mut buffer) {
            Ok(0) => {
                println!("Connection closed by client");
                break;
            }
            Ok(n) => {
                println!("Received: {}", String::from_utf8_lossy(&buffer[..n]));
                stream.write_all(&buffer[..n]).expect("Failed to write to client");
            }
            Err(e) => {
                println!("Error reading from stream: {}", e);
                break;
            }
        }
    }
}

fn main() -> std::io::Result<()> {
    let listener = TcpListener::bind("192.168.1.7:8080")?;
    println!("Server listening on 192.168.1.7:8080");
    
    for stream in listener.incoming() {
        match stream {
            Ok(stream) => {
                println!("New connection: {}", stream.peer_addr()?);
                thread::spawn(move || {
                    handle_client(stream);
                });
            }
            Err(e) => {
                println!("Connection failed: {}", e);
            }
        }
    }
    
    Ok(())
}
