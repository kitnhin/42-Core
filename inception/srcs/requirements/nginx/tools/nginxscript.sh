#!/bin/bash
echo "Nginx now is running!" 

# nginx = starts nginx
# -g = tells nginx to override wtv daemon options in its config and forcefully "daemon off"
# daemon off = says to run nginx in the foreground instead of background to keep the docker container running, if not the container will shut down
nginx -g "daemon off;"