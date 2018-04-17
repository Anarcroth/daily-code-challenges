import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextArea;
import javax.swing.JTextField;

public class coordinatesystem {

	private JButton convert;
	private JTextField textField1;
	private JTextField textField2;
	private JPanel panel1;
	private JTextArea textArea1;

	public coordinatesystem() {

		convert.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {

				JOptionPane.showMessageDialog(null, "Convert coordinates");
			}
		});
	}

	public static void main(String[] args) {
		JFrame frame = new JFrame("Coordinates");
		frame.setContentPane(new coordinatesystem().panel1);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.pack();
		frame.setVisible(true);
	}

}
