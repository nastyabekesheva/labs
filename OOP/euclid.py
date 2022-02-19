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

        while rn2 != 0:
            q = int(rn / rn1)
            rn2 = rn - q * rn1
            print(f"{rn} = {rn1}*{q} + {rn2}")
            rn = rn1
            rn1 = rn2
        
        return rn
       


if __name__ == '__main__':
    a = Number(633)
    b = Number(497)
    g = a.__gcd__(b)
    print(f"\n gcd = {g}")
