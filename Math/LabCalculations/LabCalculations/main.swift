//
//  main.swift
//  LabCalculations
//
//  Created by Nastya Bekesheva on 05.04.2022.
//

import Foundation

func fillData(N: Double, M: Double, m: Double, h1_1: Double, h1_2: Double, h2_1: Double, h2_2: Double, t: Array<Double>) -> [String : Array<Double>] {

    var data: [String : Array<Double>] = ["N": [], "M": [], "m": [], "h1": [], "h2": [], "t": [], "<t>": [], "t-<t>": [], "a(theor)": [], "a(prac)": [], "Δa": [], "ε(a)": [], "g": [], "g(theor)": [], "Δg": [], "1/m": [], "ε(g)": []]

    /*      FILLING IN INITIAL DATA     */

    data["N"] = Array(repeating: N, count: 20)

    data["M"] = Array(repeating: M, count: 20)

    data["m"] = Array(repeating: m, count: 20)

    data["h1"] = Array(repeating: h1_1, count: 10)
    data["h1"]!.append(contentsOf: Array(repeating: h1_2, count: 10))

    data["h2"] = Array(repeating: h2_1, count: 10)
    data["h2"]!.append(contentsOf: Array(repeating: h2_2, count: 10))

    data["t"]!.append(contentsOf: t)

    /*      FILLING IN CALCULATED DATA       */

    data["<t>"] = Array(repeating: data["t"]!.reduce(0.0, +) / Double(data["t"]!.count), count: 20)
    
    for i in 0...19{
        data["t-<t>"]!.append(data["t"]![i] - data["<t>"]![i])
    }

    for i in 0...19{
        data["a(theor)"]!.append(9.81 * data["m"]![i] / (2 * data["M"]![i] + data["m"]![i]))
    }

    for i in 0...19{
        data["a(prac)"]!.append((data["h2"]![i] * data["h2"]![i]) / (2 * data["h1"]![i] * data["<t>"]![i] * data["<t>"]![i]))
    }
    for i in 0...19{
        data["Δa"]!.append(data["a(theor)"]![i] - data["a(prac)"]![i])
    }

    for i in 0...19{
        data["ε(a)"]!.append((data["a(theor)"]![i] - data["a(prac)"]![i]) / data["a(prac)"]![i])
    }

    for i in 0...19{
        data["g"]!.append(data["a(prac)"]![i] * (2 * data["M"]![i] + data["m"]![i]) / data["m"]![i])
    }

    data["g(theor)"] = Array(repeating: 9.81, count: 20)

    for i in 0...19{
        data["Δg"]!.append(data["g(theor)"]![i] - data["g"]![i])
    }

    for i in 0...19{
        data["1/m"]!.append(1 / data["m"]![i])
    }

    for i in 0...19{
        data["ε(g)"]!.append((data["g(theor)"]![i] - data["g"]![i]) / data["g"]![i])
    }
    
    return data
}
let table1 = fillData(N: 10.0, M: 0.06152, m: 0.006, h1_1: 0.135, h1_2: 0.085, h2_1: 0.280, h2_2: 0.330, t: [0.82, 0.81, 0.81, 0.80, 0.80, 0.81, 0.81, 0.81, 0.82, 0.81, 1.21, 1.23, 1.24, 1.21, 1.22, 1.23, 1.24, 1.20, 1.22, 1.24])

let table2 = fillData(N: 10.0, M: 0.06152, m: 0.014, h1_1: 0.135, h1_2: 0.085, h2_1: 0.280, h2_2: 0.330, t: [0.53, 0.52, 0.50, 0.53, 0.54, 0.51, 0.52, 0.51, 0.54, 0.51, 0.84, 0.86, 0.84, 0.81, 0.84, 0.83, 0.84, 0.85, 0.85, 0.85,])

let table3 = fillData(N: 10.0, M: 0.06152, m: 0.016, h1_1: 0.135, h1_2: 0.085, h2_1: 0.280, h2_2: 0.330, t: [0.49, 0.48, 0.48, 0.49, 0.48, 0.49, 0.48, 0.48, 0.49, 0.48, 0.74, 0.71, 0.79, 0.71, 0.72, 0.71, 0.71, 0.76, 0.72, 0.75])

print("Teble 1:")
dump(table1)
print("\n")
print("Teble 2:")
dump(table2)
print("\n")
print("Teble 3:")
dump(table3)
