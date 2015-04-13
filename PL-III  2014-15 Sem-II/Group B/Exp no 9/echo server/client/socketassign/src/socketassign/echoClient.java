package socketassign;

import java.awt.EventQueue;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;
import java.net.UnknownHostException;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTextArea;
import javax.swing.JTextField;

public class echoClient {

	private JFrame frame;
	private JTextField textField;
	private JTextField textField_1;
	Socket echoSocket;
	PrintWriter out;
	BufferedReader in;
	private JTextField textField_2;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					echoClient window = new echoClient();
					window.frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the application.
	 */
	public echoClient() {
		initialize();
	}

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		
		
		
		frame = new JFrame();
		frame.setBounds(100, 100, 450, 300);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.getContentPane().setLayout(null);
		
		JLabel lblNewLabel = new JLabel("IP address of server");
		lblNewLabel.setBounds(20, 11, 117, 14);
		frame.getContentPane().add(lblNewLabel);
		
		textField = new JTextField();
		textField.setBounds(10, 29, 127, 20);
		frame.getContentPane().add(textField);
		textField.setColumns(10);
		
		JLabel lblMessage = new JLabel("Message");
		lblMessage.setBounds(47, 131, 46, 14);
		frame.getContentPane().add(lblMessage);
		
		textField_1 = new JTextField();
		textField_1.setBounds(10, 160, 127, 20);
		frame.getContentPane().add(textField_1);
		textField_1.setColumns(10);
		
		JLabel lblSentMessages = new JLabel("Sent messages");
		lblSentMessages.setBounds(266, 21, 98, 14);
		frame.getContentPane().add(lblSentMessages);
		
		JTextArea textArea = new JTextArea();
		textArea.setBounds(175, 44, 249, 60);
		frame.getContentPane().add(textArea);
		
		JLabel lblReceivedMessages = new JLabel("Received messages");
		lblReceivedMessages.setBounds(266, 131, 117, 14);
		frame.getContentPane().add(lblReceivedMessages);
		
		JTextArea textArea_1 = new JTextArea();
		textArea_1.setBounds(175, 158, 249, 60);
		frame.getContentPane().add(textArea_1);
		
		JButton btnConnect = new JButton("Connect");
		btnConnect.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent arg0) {
				try {
					echoSocket = new Socket(textField.getText(), Integer.parseInt(textField_2.getText()));
					out = new PrintWriter(echoSocket.getOutputStream(), true);
					in = new BufferedReader(new InputStreamReader(echoSocket.getInputStream()));
				} catch (UnknownHostException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
		});
		btnConnect.setBounds(20, 97, 89, 23);
		frame.getContentPane().add(btnConnect);
		
		JButton btnSend = new JButton("Send");
		btnSend.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent arg0) {
				String usrInput = textField_1.getText();
				//System.out.println("here");
				out.println(usrInput);
				
				textArea.append(usrInput + "\n");
				try {
					textArea_1.append(in.readLine());
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
		});
		btnSend.setBounds(31, 191, 89, 23);
		frame.getContentPane().add(btnSend);
		
		JButton btnNewButton = new JButton("End Connection");
		btnNewButton.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent arg0) {
				out.close();
				try {
					in.close();
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
				try {
					echoSocket.close();
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
		});
		btnNewButton.setBounds(132, 227, 189, 23);
		frame.getContentPane().add(btnNewButton);
		
		JLabel lblPort = new JLabel("port");
		lblPort.setBounds(60, 49, 46, 14);
		frame.getContentPane().add(lblPort);
		
		textField_2 = new JTextField();
		textField_2.setBounds(10, 66, 127, 20);
		frame.getContentPane().add(textField_2);
		textField_2.setColumns(10);
	}
}
