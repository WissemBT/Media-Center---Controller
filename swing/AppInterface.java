/**
 * Wissem BEN BETTAIEB
 * 2022
 */
import javax.swing.*;
import java.awt.event.*;
import java.awt.BorderLayout;
import java.awt.Dimension;

/**
 * This is the interface that will be considered as the client
 * of our server
 * 
 */
public class AppInterface extends JFrame{
    private static final long serialVersionUID = 1L;
    JTextArea textArea;
    JTextField textField;
    JButton findButton,playButton,closeButton;
    JScrollPane scrollPane;
    JToolBar toolBar;
    JMenuBar menuBar;
    JMenu menu;
    Client client;
    
    public AppInterface(String host,int port){
        try {
            client = new Client(host, port);
          }
          catch (Exception e) {
            System.err.println("Client: Couldn't connect to "+host+":"+port);
            System.exit(1);
          }

        textArea = new JTextArea(25,25);
        textField = new JTextField("WRITE FILE NAME HERE");
        textField.setColumns(25);
        
        findButton = new JButton(new FindAction("Find"));
        playButton = new JButton(new PlayAction("Play"));
        closeButton = new JButton(new CloseAction("Close"));
        findButton.setPreferredSize(new Dimension(50,25));
        playButton.setPreferredSize(new Dimension(50,25));
        closeButton.setPreferredSize(new Dimension(50,25));

        scrollPane = new JScrollPane(textArea);
        toolBar = new JToolBar();

        menuBar = new JMenuBar();
        menu = new JMenu("Menu");
        menu.add(new JMenuItem(new FindAction("Find")));
        menu.add(new JMenuItem(new PlayAction("Play")));
        menu.add(new JMenuItem(new CloseAction("Close")));
        menuBar.add(menu);
        setJMenuBar(menuBar);
    
        toolBar.add(findButton);
        toolBar.add(playButton);
        toolBar.add(closeButton);
        toolBar.add(textField);

        add(toolBar,BorderLayout.NORTH);
        add(scrollPane,BorderLayout.SOUTH);

        textArea.append("EXISTANT MEDIA FILES IN THE SERVER ARE : \n");
        textArea.append("   FIRST_PHOTO, SECOND_PHOTO , FIRST_VIDEO\n");
        textArea.append("   YOU CAN EITHER SEARCH OR PLAY THEM\n");

        
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        pack();
        setVisible(true);
    }
    /**
     * This class will send a "play" request to our server
     */
    class PlayAction extends AbstractAction{
        private static final long serialVersionUID = 1L;
        public PlayAction(String input){
            super(input);
        }
        public void actionPerformed(ActionEvent e){
            textArea.append("PLAY BUTTON CLICKED\n");
            String response = client.send("play "+textField.getText());
            textArea.append(response);
            textArea.append("\n");
        }
    }
    /**
     * This class will send a "find" request to our server
     */
    class FindAction extends AbstractAction{
        private static final long serialVersionUID = 1L;
        public FindAction(String input){
            super(input);
        }
        public void actionPerformed(ActionEvent e){
            textArea.append("FIND BUTTON CLICKED\n");
            String response = client.send("find "+textField.getText());
            textArea.append(response);
            textArea.append("\n");
        }
    }
    /**
     * This class will close the execution
     */
    class CloseAction extends AbstractAction{
        private static final long serialVersionUID = 1L;
        public CloseAction(String input){
            super(input);
        }
        public void actionPerformed(ActionEvent e){
            textArea.append("EXIT\n");
            System.exit(0);
        }
    }

    public static void main(String argv[]){
        new AppInterface("localhost", 3331);
    }
   
    
}
