import csv


def fieldnames_and_immutable_rows(filepath):
    with open(filepath) as file:
        reader = csv.DictReader(file)
        rows = tuple(reader)

        return reader.fieldnames, rows


def file_read(filepath):
    with open(filepath) as file:
        return file.read()
