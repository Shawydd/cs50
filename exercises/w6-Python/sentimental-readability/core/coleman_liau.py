from classes.text_stats import TextStats


def coleman_liau_formula(stats: TextStats) -> int:
    # Apply Coleman-Liau index formula
    roundness = 3

    L = round((stats.letters / stats.words) * 100, roundness)
    S = round((stats.sentences / stats.words) * 100, roundness)

    return int(0.0588 * L - 0.296 * S - 15.3)
