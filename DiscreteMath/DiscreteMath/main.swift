//
//  main.swift
//  DiscreteMath
//
//  Created by Nastya Bekesheva on 07.04.2022.
//

/*         Algorithms for course of Discrete Math 2(Number theory)         */

import Foundation

/*      Greates Common Divisor      */

func GCD(a: Int, b: Int) -> (gcd: Int, r: [Int], q: [Int], u: [Int], v: [Int]){
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
        print("\(r[i-1]) = \(r[i])*\(q[i-1]) + \(r[i+1])")
    }
    return (gcd: r[r.count - 2], r: r, q: q, u: u, v: v)
}

/*      Linear Diophantine Equation        */

func LDE(equationPassed: String) -> String{
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

print(GCD(a: 5, b: 3))
print(LDE(equationPassed: "18x+9y=27"))


