from dataclasses import dataclass


@dataclass
class TextStats:
    letters: int
    words: int
    sentences: int

    @classmethod
    def get_stats(cls, text: str) -> "TextStats":
        # Count letters, words and sentences directly from text
        letters = sum(char.isalpha() for char in text)
        words = len(text.split()) or 1   # avoid division by zero with truthy
        sentences = sum(char in ".!?" for char in text)

        return cls(letters, words, sentences)
