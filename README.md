# lofi-defense-system

This was an assignment I came up near the end of last year's class. Calling this lofi is still an overstatement of the fidelity of this model. It is really simple and hardly models anything - but it is enough to be interesting and can be configured in a few ways.

Just to get started, this should be buildable and runnable on `clamshell`. Once you SSH and clone the repo, you will need to pull the dependencies. I added a shell script to do this. It will clone a few repos to your home area. All in all, you can build and run everything with the following:

```
git clone git@github.com:Lnk2past/lofi-defense-system.git
cd lofi-defense-system
./get_deps.sh
make clamshell
make
./main.exe data/configuration.json
make move-plot
```

This will result in a an HTML file named "defense.html" in your current directory as well as copied to your FTP server at `clam.rutgers.edu/~NETID`.

## Breakdown

The code consists of ultra basic models for projectiles, a radar, a weapon system, and an environment. The projectile just implements basic kinematics. The environment model is used to simply apply drag.

The radar model implements an alpha-beta-gamma filter. The projectile is passed to the radar, which then has a noise applied to it based on its distance from the radar. If the radar is not already tracking, then if checks if the projectile is in range - if it is in rang e then the initial track is populated. The track object is then used in subsequent updates along with the signal (raw  + noise) to update the filter.

The weapon system is set up to have a "cooldown" so that it needs to pause between shots on the threat. If the weapon system is available it will check if the projectile is in range - if it is then it just applies dead-reckoning to the projectile (using the radar's filtered value) to attempt to figure out where to fire its salvo. Salvo's are stored in a vector which are updated separately. If a salvo comes within a certain radius of the threat then a kill is marked and the sim ends - salvos also have a fuse timer aften which when they expire they are removed from the sim.

That is it in a nutshell, im sure there are some details I missed.The code is designed to run from a JSON config - check out the default config to see what you can tweak.
