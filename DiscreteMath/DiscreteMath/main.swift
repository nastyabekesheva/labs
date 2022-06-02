//
//  main.swift
//  DiscreteMath
//
//  Created by Nastya Bekesheva on 07.04.2022.
//

/*         Algorithms for course of Discrete Math 2(Number theory)         */

import Foundation

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
//        print("\(r[i-1]) = \(r[i])*\(q[i-1]) + \(r[i+1])")
    }
    return (gcd: r[r.count - 2], r: r, q: q, u: u, v: v)
}

/*      Least Common Multiplier      */

func LCM(a: Int, b: Int) -> Int{
    let d = GCD(a: a, b: b).gcd
    
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
                
                let gcd = GCD(a: a_0, b: b_0)
                print("")
                let x_0 = gcd.u[gcd.u.count-2]
                let y_0 = gcd.v[gcd.v.count-2]
                
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
            M = 1
        }
        else{
            M = Int(pow(Double(N),Double(number - 2))) % number
        }
        
        allN.append(N)
        allM.append(M)
        
    }
    
    var x = 0
    
    for i in 0...n.count-1{
        x += remainder[i] * allN[i] * allM[i]
    }
    
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
    print(factors)
    factors = Array(Set(factors))
    
//    for i in 2...n-1{
//        if GCD(a: i, b: n).gcd == 1{
//            result += 1
//        }
//    }
    
    for prime in factors{
        result *= Double((1 - 1 / Double(prime)))
    }
    
    return Int(result)
}

func bigMod(x: Int, power: Int, n: Int) -> Int{
    var x = x
    var power = power
    var n = n
    
    if GCD(a: x, b: n).gcd == 1{
        print("r")
        let nFactors = primeFactors(n: n)
        let a = x % n
        let b = power % (n - 1)
        print(a, b)
        
        return Int(pow(Double(a), Double(b)))
        
    }
    
    return 0
}

print("\nGCD\n")
print(GCD(a: 5, b: 3))
print("\nLCM\n")
print(LCM(a: 5, b: 3))
print("\nEquation\n")
print(LDE(equationPassed: "18x+9y=27"))
print("\nCRT\n")
print(CRT(n: [2, 3, 7], remainder: [1, 2, 3]))
print("\nEuler\n")
print(Euler(n: 32))
print("\nPrimes\n")
print(primeFactors(n: 315))
print("Long mod")
print(bigMod(x: 5555, power: 2222, n: 7))
