import time
import matplotlib.pyplot as plt


def _fixed_n_comparison(funcs, n: int) -> dict:
    results = {}

    for func in funcs:
        start_time = time.time()
        func(n)
        end_time = time.time()
        results[func.__name__] = end_time - start_time

    return results


def plot_fixed_n_comparison(algs, n):
    """
    WARNING

    This might be shitcode.
    """
    res = _fixed_n_comparison(algs, n=n)

    labels = [alg[4:] for alg in res.keys()]
    values = list(res.values())

    fig, ax = plt.subplots(1, 2, figsize=(12, 4))

    fig.suptitle(f"Fibonacci Computation Time (n={n})", fontsize=16, y=1.03)

    for a in ax:
        plt.setp(a.get_xticklabels(), rotation=45, ha="right")

    p1 = ax[0].bar(labels, values)
    ax[0].set_title("Linear Scale")
    ax[0].set_ylabel("Time (seconds)")
    ax[0].grid(axis="y", alpha=0.4)
    ax[0].bar_label(p1, label_type="edge", padding=3, fontsize=8, fmt="%.4f")

    p2 = ax[1].bar(labels, values, color=(0.9, 0.3, 0.2))
    ax[1].set_yscale("log")
    ax[1].set_title("Log Scale")
    ax[1].set_ylabel("Log Time")
    ax[1].bar_label(p2, label_type="edge", padding=3, fontsize=8, fmt="%.4f")

    plt.show()
