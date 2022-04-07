class Number:
    def __init__(self, value):
        self.num = value

    def __gcd__(self, other):
        if self.num > other.num:
            rn = self.num
            rn1 = other.num
            rn2 = 1
        elif self.num < other.num:
            rn = other.num
            rn1 = self.num
            rn2 = 1
        else:
            print(self.num)
            rn2 = 0
        u = [1, 0]
        v = [0, 1]
        i = 0

        while rn2 != 0:
            i += 1
            q = int(rn / rn1)
            u.append(u[i-1]-u[i]*q)
            v.append(v[i-1]-v[i]*q)
            rn2 = rn - q * rn1
            print(f"{rn} = {rn1}*{q} + {rn2}")
            rn = rn1
            rn1 = rn2
        
        print("u: ", end = " ")
        for i in range(len(u)-1):
            print(u[i], end = " ")
        print("\nv: ", end = " ")
        for i in range(len(v)-1):
            print(v[i], end = " ")

        return rn
       


if __name__ == '__main__':
    a = Number(5819)
    b = Number(791)
    g = a.__gcd__(b)
    print(f"\n gcd = {g}")
