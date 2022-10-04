import pyqextract

p = pyqextract.PyQExtract(
    "/mnt/data_v1/capture/history3",  # data_folder
)
print(p)

data_dict = p.read_file(
    "BarRecord-20220913._1h.tcap",    # tcap_filename
    ["ALT"]                           # symbols
)
print(data_dict.shape)
print(data_dict)
