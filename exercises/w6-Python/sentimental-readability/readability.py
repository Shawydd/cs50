from classes.text_stats import TextStats
from core.coleman_liau import coleman_liau_formula
from utils.constants import MAX_GRADE, MIN_GRADE


def main():
    user_input = input("Text: ")

    # Build stats object directly from text
    stats = TextStats.get_stats(user_input)

    # Compute grade using formula
    grade = coleman_liau_formula(stats)

    # Handle bounds (before grade 1 or grade 16+)
    if grade < MIN_GRADE:
        print(f"Before Grade {MIN_GRADE}")
    elif grade > MAX_GRADE:
        print(f"Grade {MAX_GRADE}+")
    else:
        print(f"Grade {grade}")


if __name__ == "__main__":
    main()
