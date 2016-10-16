from facts_pb2 import TDocument
import sys


def ReadVarint32(f):
    offset = 0
    result = 0
    byte = f.read(1)
    while byte != "":
        if 0 == offset:
            result = ord(byte) & 0x7F
        else:
            result = result | ((ord(byte) & 0x7F) << offset)

        offset += 7

        if (ord(byte) & 0x80) == 0:
            break

        byte = f.read(1)

    return result


for a in sys.argv[1:]:
    ff = open(a, "rb")

    size = ReadVarint32(ff)
    while size > 0:
        data = ff.read(size)
        doc = TDocument()
        doc.ParseFromString(data)

        for fg in doc.FactGroup:

            for f in fg.Fact:
                text_start_pos = f.Attr.TextPos
                text_len = f.Attr.TextLen
                object_type = ""
                object_text = ""

                for field in f.Field:
                    if field.Name == "Type":
                        object_type = field.Value
                    else:
                        if len(object_text) > 0:
                            object_text += " "
                        object_text += field.Value

                #out = "%s %d %d # %s" % (object_type, text_start_pos, text_len, object_text)
                out = "%s %d %d" % (object_type, text_start_pos, text_len)
                print out.encode('utf-8')

        size = ReadVarint32(ff)

    ff.close;
