// Seealso: https://atcoder.jp/contests/abc061/tasks/abc061_a

fun main(args: Array<String>) {
    val list: List<Int> = readLine()!!.split(" ").map { it.toInt() }

    val ans: String
    if (list[2] >= list[0] && list[2] <= list[1]) {
        ans = "Yes"
    } else {
        ans = "No"
    }
    println(ans)
}
