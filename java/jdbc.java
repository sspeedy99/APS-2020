import java.sql.*;

class JDBCExample {
    public static void main(String [] args){
        try{
            String dbUrl = "jdbc:mysql://localhost:3306/emp";
            String username = "root";
            String password = "shashi";
    
            // get a connection
            Connection myConnection = DriverManager.getConnection(dbUrl,username,password);
            Statement myStatement = myConnection.createStatement();
            ResultSet myResultSet = myStatement.executeQuery("Select * from emps;");

            while(myResultSet.next()) {
                System.out.println(myResultSet.getString("name"));
            }
        }
        catch(Exception e){
            System.out.println(e);
        }


    }
}