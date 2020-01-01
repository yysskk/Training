import Foundation

func main() {
    let input_line: String = readLine()!
    let array: [Int] = input_line.components(separatedBy: " ").compactMap { Int($0) ?? 0 }

    let ans: String
    if (array[2] >= array[0] && array[2] <= array[1]) {
        ans = "Yes"
    } else {
        ans = "No"
    }
    
    print(ans)

    return
}