for i, j in range(50000):
    if i * j >= 100000 * 100000:
        break;
    else:
        ans += 1 / i / j;
    