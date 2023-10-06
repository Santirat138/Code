from faker import Faker

people = Faker()
for _ in range(5):
    print("Name: ", people.name())
    print("Email: ", people.email(),"\n")
