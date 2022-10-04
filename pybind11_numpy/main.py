import pyqextract
import pandas as pd

# Create data reader
p = pyqextract.PyQExtract(
    "/mnt/data_v1/capture/history3",  # data_folder
)

# Read particular file
# - return string columns as Python list of strings
#   - saves hustle of creating Python strings in C++
# - return long/double columns as proper numpy arrays
#   - returning numpy array from c++ does not copy data
#   - converting numpy array to pd.DataFrame also does not copy data
#   - add more array types as required: char, unsigned char, short, int, etc
# - return datetime columns as nanosecond timestamp in numpy array
#   - conversion to pd.Timestamp is very fast, much faster than parsing string
data_dict = p.read_file(
    "BarRecord-20220913._1h.tcap",    # tcap_filename
    ["ALT"]                           # symbols
)
# data_dict = {
#   "MyStringColumn": ["0", "1", "2", "3"],
#   "MyLongColumn": np.array([0, 1, 2, 3], dtype=np.int64),
#   "MyFloatColumn": np.array([0.0, 1.0, 2.0, 3.0], dtype=np.float64)
#   "MyDatetimeColumn": np.array([0, 1, 2, 3], dtype=np.int64),
# }

# Convert to DataFrame
# - convert datetime on Python side because Pandas in C++/PyBind11 is hard
df = pd.DataFrame(data=data_dict)
df["MyDatetimeColumn"] = pd.to_datetime(df.MyDatetimeColumn)
#                 MyDatetimeColumn  MyFloatColumn  MyIntColumn MyStringColumn
# 0  1970-01-01 00:00:00.000000000            0.0            0              0
# 1  1970-01-01 00:00:00.000000001            1.0            1              1
# 2  1970-01-01 00:00:00.000000002            2.0            2              2
# 3  1970-01-01 00:00:00.000000003            3.0            3              3
# 4  1970-01-01 00:00:00.000000004            4.0            4              4
# ..                           ...            ...          ...            ...
# 95 1970-01-01 00:00:00.000000095           95.0           95             95
# 96 1970-01-01 00:00:00.000000096           96.0           96             96
# 97 1970-01-01 00:00:00.000000097           97.0           97             97
# 98 1970-01-01 00:00:00.000000098           98.0           98             98
# 99 1970-01-01 00:00:00.000000099           99.0           99             99

print(df)
print(df.info())
