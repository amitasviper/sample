import java.net.*;
import java.io.*;

class Server implements Runnable
{
 ServerSocket svrSkt;
 Thread connThread;
 boolean connFlag;

 Server(int port) throws IOException
 {
  //Open a port if available, otherwise raise Exception
  svrSkt = new ServerSocket(port);

  //create a new thread for accepting client connections
  connFlag = true;
  connThread = new Thread(this);
  connThread.start();

 }//Server(int port)  

 public void run()
 {
   try
   {
    //after every 1000 millisSeconds bring the connThread out of accept through an Exception
    svrSkt.setSoTimeout(1000);
   }
   catch(Exception ex)
   {}
   while(connFlag)
   {
     acceptConnection();
   }//while

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
  System.out.println("Waiting for a client connection request ...");

  //Blocks the current thread until connection request is received
  //On request accepts the connection
  //Forms and returns a Socket for bidirectional communiction with client 
  Socket s = svrSkt.accept(); 
  System.out.println("... Got a client connection");

  //create a new thread to process Socket s
  new Processor(s);
  }
  catch(IOException ex)
  {}

 }//acceptConnection

 public static void main(String args[])
 {
  try
  {
   Server s = new Server(8989);
  }
  catch(IOException ex)
  {
   System.out.println("Err : " + ex);
  }
 }//main
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
  //Use Socket for bidirectional communication
  InputStream ips = client.getInputStream();
  OutputStream ops = client.getOutputStream();

  //ips/ops to read/write BYTES
  //Use DataInputStream / DataOutputStream for i/o of Java datatypes

  DataInputStream din = new DataInputStream(ips);
  DataOutputStream dout = new DataOutputStream(ops);

  boolean flag = false;
  String s1, s2;
  do
  {
    //read a string
    s1 = din.readUTF();
   //process  
    s2 = echo(s1);
   //write back result
   dout.writeUTF(s2);
  
   //cycle
   flag = din.readBoolean();

  }while(flag);
  //close the connection
  client.close();
  }
  catch(IOException ex)
  {
   System.out.println("Err : " + ex);
  }

 }//run

 String echo(String x)
 {
   String sol;
   sol = "{ " + x.toUpperCase() + " }";
   return sol;
 }
}

