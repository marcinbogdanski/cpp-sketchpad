import example


in_flight = dict()
in_flight["2022010100000009"] = {
    "CI": "2022010100000000",
    "symbol": "ABCD",
    "quantity": 123,
    "provider": "best4",
    "status": "requested",
    "offered_qty": 0,
    "offered_price": 123.456,
    "error_msg": "",
}

# in_flight["2022010100000009"] = {
#     "CI": "2022010100000000",
#     "symbol": "ABCD",
#     "provider": "best4",
#     "status": "requested",
#     "error_msg": "",
# }

p = example.MyClass(in_flight)

p.print_dict()

p.assign_item("Alan")

print(in_flight)
print("end")