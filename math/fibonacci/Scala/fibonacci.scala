object fibonacci {
  def main(args: Array[String]): Unit = {
    print("Input the nth fibonacci number you'd like to compute: ")
    val x: Int = scala.io.StdIn.readLine.toInt
    println(nthFib(x))
  }

  def nthFib(n: Int): Int = {
    if (n == 1)
      return 1
    else if (n == 2)
      return 1
    else
      return nthFib(n-2) + nthFib(n-1)
  }
}