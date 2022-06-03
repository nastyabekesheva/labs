//
//  main.swift
//  DiscreteMath
//
//  Created by Nastya Bekesheva on 07.04.2022.
//

/*         Algorithms for course of Discrete Math 2(Number theory)         */

import Foundation
import Table

/*      Greates Common Divisor      */

func GCD(a: Int, b: Int) -> (gcd: Int, r: [Int], q: [Int], u: [Int], v: [Int]) {
    var q: [Int] = []
    var u: [Int] = [1, 0]
    var v: [Int] = [0, 1]
    var r: [Int] = []
    var i = 0
    
    if a > b{
        r.append(a)
        r.append(b)
    }
    else if a < b{
        r.append(b)
        r.append(a)
    }
    else{
        r.append(0)
        r.append(0)
        r.append(0)
    }
    
    while r[r.count - 1] != 0{
        i += 1
        q.append(Int(r[i-1] / r[i]))
        u.append(u[i-1] - u[i] * q[i-1])
        v.append(v[i-1] - v[i] * q[i-1])
        r.append(r[i-1] - q[i-1] * r[i])
        print("\(r[i-1]) = \(r[i])\u{22C5}\(q[i-1]) + \(r[i+1])")
    }
    u.removeLast()
    v.removeLast()
    q.removeLast()
    
    var newQ: [String] = [" q\u{1D62} ", ""]
    var newU: [String] = [" u\u{1D62} "]
    var newV: [String] = [" v\u{1D62} "]
    newQ.append(contentsOf: q.map(String.init))
    newU.append(contentsOf: u.map(String.init))
    newV.append(contentsOf: v.map(String.init))
    print("")
    print(table: [newQ, newU, newV] )
    
    print("gcd(\(a), \(b)) = \(r[r.count - 2])")
    
    return (gcd: r[r.count - 2], r: r, q: q, u: u, v: v)
}

/*      Least Common Multiplier      */

func LCM(a: Int, b: Int) -> Int{
    let d = GCD(a: a, b: b).gcd
    print("lcm(\(a), \(b)) = \(a)\u{22C5}\(b) / gcd(\(a), \(b))\nlcm(\(a), \(b)) = \((a * b)/d)")
    
    return (a * b)/d
}

/*      Linear Diophantine Equation        */

func LDE(equationPassed: String) -> String {
    var a, b, c: Int
    var equation = equationPassed
    
    if let range = equation.range(of: "x") {
        let firstPart = equation[equation.startIndex..<range.lowerBound]
        a = Int(firstPart)!
        
        equation = equation.replacingOccurrences(of: "\(a)x ?", with: "", options: [.caseInsensitive, .regularExpression])
        
        if let newRange = equation.range(of: "y"){
            let newFirstPart = equation[equation.startIndex..<newRange.lowerBound]
            b = Int(newFirstPart)!
            
            equation = equation.replacingOccurrences(of: "\(b)y= ?", with: "", options: [.caseInsensitive, .regularExpression])
            
            c = Int(equation)!
            
            let d = GCD(a: a, b: b).gcd
            print("")
            
            if c % d == 0{
                let a_0 = a / d
                let b_0 = b / d
                let c_0 = c / d
                
                print("Updated equation:\n\(a_0)x + \(b_0)y = \(c_0)\n")
                
                let gcd = GCD(a: a_0, b: b_0)

                let x_0 = gcd.u[gcd.u.count-1]
                let y_0 = gcd.v[gcd.v.count-1]
                
                print("\nSpecial case (x\u{2080}, y\u{2080}) : (\(x_0), \(y_0))\n")
                
                equation = "x = \(x_0 * c_0) + \(b_0)k\ny = \(y_0 * c_0) - \(a_0)k"
                
                return equation
            }
            else{
                equation = "∅"
                
                return equation
            }
        }
        else{
            equation = "∅"
            
            return equation
        }
    }
    equation = "∅"
    
    return equation
    
}

/*      Chinese Remainder Theorem        */

func CRT(n: [Int], remainder: [Int]) -> (N: Int, allN: [Int], allM: [Int], x: Int) {

    let bigN = n.reduce(1, { x, y in x * y})
    var allN = [Int]()
    var allM = [Int]()
    
    for number in n{
        let N = bigN / number
        var M = 1
        
        if number == 1{
            M = 0
        }
        else{
            let d = GCD(a: number, b: N)
            M = d.v[d.v.count-1]
            M = (M % number + number) % number
            
            if M == 0 { M = 1}
        }
        
        allN.append(N)
        allM.append(M)
        
    }
    
    var x = 0
    
    for i in 0...n.count-1{
        x += remainder[i] * allN[i] * allM[i]
    }
    
    var newn: [String] = [" n\u{1D62} ", ""]
    var newN: [String] = [" N\u{1D62} "]
    var newM: [String] = [" M\u{1D62} "]
    newn.append(contentsOf: n.map(String.init))
    newN.append(contentsOf: allN.map(String.init))
    newM.append(contentsOf: allM.map(String.init))
    print("")
    print(table: [newn, newN, newM] )
    print("x \u{2261} \(x % bigN) ( mod \(bigN) )")
    
    return (bigN, allN, allM, x)
    
}

/*      Prime Factorization        */

func primeFactors(n: Int) -> [Int] {
    var  n = n
    var  p = 2
    var factors = [Int]()
    
    while n > 1{
        if n % p == 0{
            n = n / p
            
            factors.append(p)
        }
        else{
            p = p + 1
        }
    }
    
    return factors
}

/*      Euler's Totient Fuction        */

func Euler(n: Int) -> Int {
    
    var result = Double(n)
    var factors = primeFactors(n: n)
    let uniqueFactors = Array(Set(factors))
    var eq = "\(n)"
//    for i in 2...n-1{
//        if GCD(a: i, b: n).gcd == 1{
//            result += 1
//        }
//    }
    
    for prime in uniqueFactors{
        result *= Double((1 - 1 / Double(prime)))
        eq.append(contentsOf: "\u{22C5}")
        eq.append(contentsOf: String(Double((1 - 1 / Double(prime)))))
    }
    
    let factorization = factors.map { String($0) }.joined(separator: "\u{22C5}")
    print("\u{1D711}(\(n)) = \u{1D711}(\(factorization)) = \(eq) = \(Int(result))")
    
    return Int(result)
}

/*      Linear Congruence        */

func LC(a: Int, b: Int, m: Int) -> Int{
    let d = GCD(a: a, b: m)
    var a = a
    var b = b
    var m = m
    
    if b % d.gcd == 0{
        a /= d.gcd
        b /= d.gcd
        m /= d.gcd
        
        let newGcd = GCD(a: a, b: m)
        var c = newGcd.v[newGcd.v.count-1]
        c = (c % m + m) % m
        print("a\u{207B}\u{00B9} \u{2261} \(c) ( mod \(m))")
        print("x \u{2261} \(c)\u{22C5}\(b) ( mod \(m)) \u{2261} \((c*b) % m)")
                   
        return (c*b) % m
    }
    
    return 0
}

func bigMod(x: Int, power: Int, n: Int) -> Int{

    
    if GCD(a: x, b: n).gcd == 1{

        _ = primeFactors(n: n)
        let a = x % n
        let b = power % (n - 1)
        print("\n\(x) \u{2261} \(a) ( mod \(n) )")
        print("\(power) \u{2261} \(b) ( mod \(n - 1) )\n")
        print("\(x)^\(power) -> \(a)^\(b)\n")
        print("\(a)^\(b) \u{2261} \(Int(pow(Double(a), Double(b))) % n) ( mod \(n) )")
        
        return Int(pow(Double(a), Double(b)))
        
    }
    
    return 0
}

print("\nGreates Common Divisor\n")
GCD(a: 123, b: 456)
print("\nLeast Common Multiplier\n")
LCM(a: 5, b: 3)
print("\nLinear Diophantine Equation\n")
print(LDE(equationPassed: "18x+9y=27"))
print("\nChinese Remainder Theorem\n")
print(CRT(n: [25, 27, 2], remainder: [16, 16, 10]))
print("\nEuler's Totient Fuction\n")
Euler(n: 32)
//print("\nPrimes\n")
//print(primeFactors(n: 315))
print("\nBig mod\n")
bigMod(x: 5555, power: 2222, n: 7)
print("\nLinear Congruence\n")
LC(a: 129, b: 209, m: 889)


