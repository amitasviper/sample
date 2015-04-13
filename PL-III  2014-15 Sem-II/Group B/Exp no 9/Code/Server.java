import java.net.*;
import java.io.*;

class Server implements Runnable
{
 ServerSocket svrSkt;
 Thread t;
 boolean flag;
 
 Server(int portNo) throws IOException
 {
   //opens a port    
   //or raises exception if port is already in use
   svrSkt = new ServerSocket(portNo);

   //create a thread for accepting connections
   flag = true;
   t = new Thread(this);
   t.start(); 
 }

 public void run()
 {
  while(flag == true)
  {
    acceptConnection();
  }
  try
  {
    //close the port
    svrSkt.close();
  }
  catch(Exception ex)
  {} 
 }

 void acceptConnection()
 {
  try
  {
   //wait and listen client connection requests. On request accept it and form a connection.
   System.out.println("Waiting For A Connection");
   Socket s = svrSkt.accept();
   System.out.println("Got A Connection");
   new Processor(s);
  }
  catch(Exception ex)
  {}
 }//acceptConnection

 public static void main(String args[])
 {
  try
  {
   Server svr = new Server(8900);
  }
  catch(Exception ex)
  {}
 }
  
}//Server

class Processor extends Thread
{
 Socket client;
 Processor(Socket s)
 {
  client = s;
  start();//activate the thread
 }

 public void run()
 {
  try
  {
    InputStream in = client.getInputStream();
    OutputStream out = client.getOutputStream();

    DataInputStream din = new DataInputStream(in);
    DataOutputStream dout = new DataOutputStream(out);

    String s, cycle;    
    do
    { 
     //input
     s = din.readUTF();
     //process
     s = echo(s);
     //output 
     dout.writeUTF(s);

     cycle = din.readUTF();
    }while(cycle.equalsIgnoreCase("yes"));

    client.close();
  }
  catch(Exception ex)
  {}

 }//run

 String echo(String data)
 {
  String reply;
  reply = "{ " + data.toUpperCase() + " }";
  return reply;
 }
}