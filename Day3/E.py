def fast_power_mod(a, b, p):
    result = 1
    base = a % p
    while b > 0:
        if b % 2 == 1:# 如果当前指数是奇数则提出一个base单独乘一下
            result = (result * base) % p
        # ————将指数提出2让base平方
        base = (base * base) % p
        b //= 2
        # ————
    return result
'''
理解：
eg.2^10->(2^2)^5->4^5->(4^4)*4->(16*2)*4->256*4
'''


# 从输入中读取 a, b, p
a, b, p = map(int, input().split())
# 计算 a^b % p
s = fast_power_mod(a, b, p)
# 打印结果
print(f"{a}^{b} mod {p}={s}")

