<!DOCTIPE html>
<html>
  <head>
  </head>
  <body>
    <h1> task to log the uptime every monday on 1:00 pm </h1>
    <p>
      <b> Open the crontab editor: Run the following command in the terminal to open the crontab file for editing: </b>
       <strong>$crontab -e</strong>
      <hr>
      <b>Add the cron job: Add the following line to schedule the uptime logging task: </b>
      <strong> 0 13 * * 1 /usr/bin/uptime >> /path/to/your/logfile.log </strong>
      <hr>
      Here's what this means : 

      0: At minute 0
      13: At 13:00 (1:00 PM)
      * *: Every day and every month
      1: Every Monday (1 represents Monday in cron)
      /usr/bin/uptime: Command to log system uptime
      >> /path/to/your/logfile.log: Redirects the output to a log file, appending the results to it.
      <hr>
      <b>
      Save and exit: After adding the line, save and exit the editor. If you're using nano, you can do this by pressing Ctrl + O to save and Ctrl + X to exit.
      </b>
    </p>
  </body>
</html>  
