import java.io.{BufferedReader, InputStreamReader}
 
object Main {
  def main(args: Array[String]) {
      var stdin =
         new BufferedReader(new InputStreamReader(System.in));
    var line = stdin.readLine();
    while(false == line.equals("42")) {
      System.out.println(line);
      line = stdin.readLine();
    }
  }
}
