* Test recovery frequency - PASS
* Always starts @ stopped
* do multiple runs & change timers while running


On Startup

1. Empty Detections & time - PASS
    STOPPED to RECOVERY after time up

2. Non target detections & time - PASS
    STOPPED to RECOVERY after time up
 
3. No Detections & time - PASS
    Bbox callback doesn't run, no status, nothing happens

4. Empty Detections & no time - PASS
    STOPPED 1 cycle then RECOVERY

5. Non target detections & time - PASS
    STOPPED 1 cycle then RECOVERY
 
6. No Detections & time - PASS
    Bbox callback doesn't run, no status, nothing happens

From STOPPED

7. Rapid Fire Detections & time - PASS
    1 WP, Heading to target while paused search, after time searching 1 cycle then Found & WP repeating

8. 1 detection & time - PASS
    1 WP, Heading to target while paused search, after time searching on repeat while in heading to target

9. Rapid Fire Detections no time - PASS
    1 WP, Heading to target, searching, then rapid repeat

10. 1 detection no time - PASS
    1 WP, Heading to target, searching 

From RECOVERY

11. Rapid Fire Detections & time - PASS
    1 WP, Heading to target while paused search, after time searching 1 cycle then Found & WP repeating

12. 1 detection & time - PASS
    1 WP, Heading to target while paused search, after time searching on repeat while in heading to target

13. Rapid Fire Detections no time - PASS
    1 WP, Heading to target, searching, then rapid repeat

14. 1 detection no time - PASS
    1 WP, Heading to target, searching 

From HEADING to target
15. if wp_reached_ & empty detections & stop time - PASS 
    STOPPED
16. if wp_reached_ & empty detections & no stop time - PASS
    RECOVERY & see recovery action
17. if wp_reached & detections at same time
    Stay in HEADING to TARGET & send a wp 
18. no detections, no wp_reached - PASS
    Stay there & stay searching
19. Rapid fire detections - PASS I THINK








