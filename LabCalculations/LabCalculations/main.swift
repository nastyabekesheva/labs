//
//  main.swift
//  LabCalculations
//
//  Created by Nastya Bekesheva on 05.04.2022.
//

import Foundation

//func fillData(N: Double, M: Double, m: Double, h1: Double, h2: Double, t: Array<Double>)

var data: [String : Array<Double>] = ["N": [], "M": [], "m": [], "h1": [], "h2": [], "t": [], "<t>": [], "t-<t>": [], "a(theor)": [], "a(prac)": [], "Δa": [], "ε(a)": [], "g": [], "g(theor)": [], "Δg": [], "1/m": [], "ε(g)": []]

/*      FILLING IN INITIAL DATA     */

data["N"] = Array(repeating: 0.0, count: 10)

data["M"] = Array(repeating: 61.52, count: 10)

data["m"] = Array(repeating: 16.0, count: 10)

data["h1"] = Array(repeating: 13.5, count: 5)
data["h1"]!.append(contentsOf: Array(repeating: 8.5, count: 5))

data["h2"] = Array(repeating: 28.0, count: 5)
data["h2"]!.append(contentsOf: Array(repeating: 33.0, count: 5))

data["t"]!.append(contentsOf: [0.82, 0.81, 0.81, 0.80, 0.80, 0.81, 0.81, 0.81, 0.82, 0.81, 1.21, 1.23, 1.24, 1.21, 1.22, 1.23, 1.24, 1.20, 1.22, 1.24])

/*      FILLING IN CALCULATED DATA       */

data["<t>"] = Array(repeating: data["t"]!.reduce(0.0, +) / Double(data["t"]!.count), count: 10)

for i in 0...9{
    data["t-<t>"]!.append(data["t"]![i] - data["<t>"]![i])
}

for i in 0...9{
    data["a(theor)"]!.append(9.81 * data["m"]![i] / (2 * data["M"]![i] + data["m"]![i]))
}

for i in 0...9{
    data["a(prac)"]!.append(pow(data["h2"]![i], 2.0) / (2 * data["h1"]![i] * pow(data["<t>"]![i], 2.0)))
}

for i in 0...9{
    data["Δa"]!.append(data["a(theor)"]![i] - data["a(prac)"]![i])
}

for i in 0...9{
    data["ε(a)"]!.append((data["a(theor)"]![i] - data["a(prac)"]![i]) / data["a(prac)"]![i])
}

for i in 0...9{
    data["g"]!.append(data["a(prac)"]![i] * (2 * data["M"]![i] + data["m"]![i]) / data["m"]![i])
}

data["g(theor)"] = Array(repeating: 9.81, count: 10)

for i in 0...9{
    data["Δg"]!.append(data["g(theor)"]![i] - data["g"]![i])
}

for i in 0...9{
    data["1/m"]!.append(1 / data["m"]![i])
}

for i in 0...9{
    data["ε(g)"]!.append((data["g(theor)"]![i] - data["g"]![i]) / data["g"]![i])
}

dump(data)
