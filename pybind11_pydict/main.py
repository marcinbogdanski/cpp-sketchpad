import example

my_dict = {
    'name': 'Molly'
}

p = example.Pet(my_dict)
print(p)

print(p.getName())
p.setName('Charly')
print(p.getName())

print(my_dict)

my_dict['name'] = 'Kitty'
print(my_dict)
print(p.getName())

