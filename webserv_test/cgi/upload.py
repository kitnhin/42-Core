#!/usr/bin/python

import os
import sys
import cgi
import cgitb

#enable error handling in the browser for debugging
cgitb.enable()

public_files_dir = "./cgi/public_files/"


# below is smth half working, i try to create another version

#get request method
#os is a std lib thing that can help get stuff abt the operating system
request_method = os.environ.get("REQUEST_METHOD")
route = os.environ.get("ROUTE")

#this gay ass function helps u read from stdin and sort the request body for u
#wtf i feel like c and cpp is a joke now
form = cgi.FieldStorage()

if request_method == "POST":

	if "file" in form:

		#file item is like a struct which contains information about the file
		file_item = form["file"]
		file_name = file_item.filename
		file_path_and_name = public_files_dir + file_name

		#create the dir if it doesnt exist
		if not os.path.exists(public_files_dir):
			os.makedirs(public_files_dir)
		
		#open file to write stuff
		#wb stands for writing mode : write binary (to take into acc files wif no words like pics)
		#include file item struct theres a "FILE" object, which we can call read() to get the file contents
		file_data = b''
		file_data = file_item.file.read()

		with open(file_path_and_name, "wb") as newfile:
			newfile.write(file_data)
		
		with open(file_path_and_name, "rb") as checkfile:
			checkfile_data = checkfile.read()

		#status msg
		msg = "Succesfully uploaded file!"
		print("HTTP/1.1 200 OK\r\n", end="")
		
	else:
		msg = "Failed to upload file"
		print("HTTP/1.1 500 Internal Server Error\r\n", end="")
	
	response_body = "<!DOCTYPE html>"
	response_body += "<html>"
	response_body += "<head></head>"
	response_body += "<body><center><h1>" + msg + "</h1></center></body>"
	response_body += "</html>"

	print("Content-Type: text/html\r\n", end="")
	print("Connection: keep-alive\r\n", end="")
	print("Content-Length: " + str(len(response_body)) + "\r\n", end="")
	print("\r\n", end="")
	print(response_body)

elif request_method == "GET":

	route_parts = route.rsplit("/")

	#check on this ltr
	file_name = route_parts[2]
	#sys.stderr.write(f"Error: {file_name}\n")

	if os.path.exists(public_files_dir + file_name):

		file_name_parts = file_name.split(".")
		file_extension = file_name_parts[1]

		with open(public_files_dir + file_name, "rb") as infile:
			response_body = infile.read()


		if(file_extension == "txt"):
			content_type = "text/plain"
			response_body = response_body.decode('utf-8')
		elif file_extension == "html":
			content_type = "text/html"
			response_body = response_body.decode('utf-8')
		elif file_extension == "css":
			content_type = "text/css"
			response_body = response_body.decode('utf-8')
		elif file_extension == "js":
			content_type = "application/javascript"
			response_body = response_body.decode('utf-8')
		elif file_extension == "json":
			content_type = "application/json"
			response_body = response_body.decode('utf-8')
		elif file_extension == "jpg" or file_extension == "jpeg":
			content_type = "image/jpeg"
		elif file_extension == "png":
			content_type = "image/png"
		elif file_extension == "gif":
			content_type = "image/gif"
		else:
			content_type = "text/plain"
		
		
		print("HTTP/1.1 200 OK\r\n", end="")


	else:
		print("HTTP/1.1 500 Internal Server Error\r\n", end="")
		response_body = "<!DOCTYPE html>"
		response_body += "<html>"
		response_body += "<head></head>"
		response_body += "<body><center><h1> Error 404: Not found</h1></center></body>"
		response_body += "</html>"
		content_type = "text/html"
	
	print("Content-Type: " + content_type + "\r\n", end="")
	print("Connection: keep-alive\r\n", end="")
	print("Content-Length: " + str(len(response_body)) + "\r\n", end="")
	print("\r\n", end="")
	print(response_body)




#rip this one oso not working

# body = b''

# while True:
# 	data = sys.stdin.buffer.read(1024)
# 	if not data:
# 		break
# 	body += data

# body_arr = body.split(b'\r\n')
# bound = body_arr[0]
# filename_start = body_arr[1].find(b'filename="') + len(b'filename="')
# filename_end = body_arr[1].find(b'"', filename_start)
# filename = body_arr[1][filename_start:filename_end]

# file_contents_start = body.find(b'\r\n\r\n') + 4
# file_contents_end = body.find(b'--', file_contents_start)
# file_contents = body[file_contents_start:file_contents_end]

# with open(public_files_dir + filename.decode("utf-8"), "wb") as newfile:
# 	newfile.write(file_contents)

# content_type = "text/html"
# msg = "Successfully added file!"

# response_body = "<!DOCTYPE html>"
# response_body += "<html>"
# response_body += "<head></head>"
# response_body += "<body><center><h1>" + msg + "</h1></center></body>"
# response_body += "</html>"

# print("HTTP/1.1 200 OK\r\n", end="")
# print("Content-Type: " + content_type + "\r\n", end="")
# print("Connection: keep-alive\r\n", end="")
# print("Content-Length: " + str(len(response_body)) + "\r\n", end="")
# print("\r\n", end="")
# print(response_body)
