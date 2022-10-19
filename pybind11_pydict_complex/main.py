import example
import json

in_flight = dict()
in_flight["2022010100000009"] = {
    "CI": "2022010100000009",
    "symbol": "ABCD",
    "quantity": 123,
    "provider": "best4",
    "status": "requested",
    "offered_qty": 0,
    "offered_price": 123.456,
    "error_msg": "",
    "assign_me_int": 0,
    "assign_me_float": 0.0,
    "assign_me_string": "",
}

# in_flight["2022010100000009"] = {
#     "CI": "2022010100000000",
#     "symbol": "ABCD",
#     "provider": "best4",
#     "status": "requested",
#     "error_msg": "",
# }

p = example.MyClass(in_flight)

print("-"*80)
print("p.print_dict()")
p.print_dict()

print("-"*80)
print("p.assign_mini_item()")
p.assign_mini_item()
print(json.dumps(in_flight, indent=2))

print("-"*80)
print('p.assign_item("2022010100000011")')
p.assign_item("2022010100000011")
print(json.dumps(in_flight, indent=2))

print("-"*80)
print('p.assign_item("2022010100000012")')
p.assign_item("2022010100000012")
print(json.dumps(in_flight, indent=2))

print("-"*80)
print(p.do_check("2022010100000012"))
print(p.do_check("2022010100000xxx"))

print("-"*80)
print(id(in_flight["2022010100000009"]))
print(id(in_flight["2022010100000011"]))
print(id(in_flight["2022010100000012"]))
print("end")