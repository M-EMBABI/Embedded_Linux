<!DOCTYPE html>
<html>
  <head>
    <title>Cron Task to Log Uptime</title>
  </head>
  <body>
    <h1>Task to Log the Uptime Every Monday at 1:00 PM</h1>

    <p>
      <b>Step 1: Open the Crontab Editor</b><br>
      Run the following command in the terminal to open the crontab file for editing:
      <br><strong>$ crontab -e</strong>
    </p>

    <hr>

    <p>
      <b>Step 2: Add the Cron Job</b><br>
      Add the following line to schedule the uptime logging task:
      <br><strong>0 13 * * 1 /usr/bin/uptime >> /path/to/your/logfile.log</strong>
    </p>

    <hr>

    <p>
      <b>Step 3: Understanding the Cron Job</b><br>
      Here's what the cron expression means:
      <ul>
        <li><b>0</b>: At minute 0</li>
        <li><b>13</b>: At 13:00 (1:00 PM)</li>
        <li><b>* *</b>: Every day and every month</li>
        <li><b>1</b>: Every Monday (1 represents Monday in cron)</li>
        <li><b>/usr/bin/uptime</b>: The command to log system uptime</li>
        <li><b>>></b>: Appends the output to a file (replace <i>/path/to/your/logfile.log</i> with the actual path to your log file)</li>
      </ul>
    </p>

    <hr>

    <p>
      <b>Step 4: Save and Exit</b><br>
      After adding the line, save and exit the editor. If you are using <b>nano</b>, you can save by pressing <strong>Ctrl + O</strong> and exit by pressing <strong>Ctrl + X</strong>.
    </p>

    <hr>

    <p>
      <b>Step 5: Verify the Cron Job</b><br>
      To ensure the cron job has been set up correctly, run the following command to list all your cron jobs:
      <br><strong>$ crontab -l</strong>
      <br>This will display the current cron jobs, including the one you just added.
    </p>

    <hr>

    <p>
      Now, every Monday at 1:00 PM, the system uptime will be logged in your specified log file.
    </p>

  </body>
</html>
