cmake_minimum_required(VERSION 3.13)
project(usaco)

set(CMAKE_CXX_STANDARD 14)

add_executable(usaco
        astar/goldb/bds/bds.cpp
        astar/goldb/bestspot/bestspot.cpp
        astar/goldb/cgiving/cgiving.cpp
        astar/goldb/contest/contest.cpp
        astar/goldb/cowroute/cowroute.cpp
        astar/goldb/dijkstra2/dijkstra2.cpp
        astar/goldb/flow/flow.cpp
        astar/goldb/hideseek/hideseek.cpp
        astar/goldb/mst2/mst2.cpp
        astar/goldb/packdel/packdel.cpp
        astar/goldb/picnic/picnic.cpp
        astar/plat/articulation/articulation.cpp
        astar/plat/balloc/balloc.cpp
        astar/plat/convexhulltrick/convex.cpp
        astar/plat/cowrun2/cowrun2.cpp
        astar/plat/cpattern/cpattern.cpp
        astar/plat/damage/damage.cpp
        astar/plat/expand/expand.cpp
        astar/plat/expand/expand1.cpp
        astar/plat/fence/fence.cpp
        astar/plat/fence6/fence6.cpp
        astar/plat/first/first.cpp
        astar/plat/gangs/gangs.cpp
        astar/plat/gourmet/gourmet.cpp
        astar/plat/island2/island2.cpp
        astar/plat/letter/letter.cpp
        astar/plat/lilypad/lilypad.cpp
        astar/plat/lineup2/lineup2.cpp
        astar/plat/lites/lites.cpp
        astar/plat/mixup2/mixup2.cpp
        astar/plat/mou/mou.cpp
        astar/plat/msched/msched.cpp
        astar/plat/nearcows/nearcows.cpp
        astar/plat/newbarn/newbarn.cpp
        astar/plat/patterns/patterns.cpp
        astar/plat/photo/photo.cpp
        astar/plat/photo2/photo2.cpp
        astar/plat/race3/race2.cpp
        astar/plat/race3/race3.cpp
        astar/plat/scc/scc.cpp
        astar/plat/schlnet/schlnet.cpp
        astar/plat/sightsee/sightsee.cpp
        astar/plat/simplify/simplify.cpp
        astar/plat/ski/ski.cpp
        astar/plat/telephone/telephone.cpp
        astar/plat/tsp/tsp.cpp
        astar/plat/vacationgold/vacationgold.cpp
        astar/plat/vidgame/vidgame.cpp
        astar/plat/wormhole/wormhole.cpp
        astar/plat/xoinc/xoinc.cpp
        cf/antimatter.cpp
        cf/arithprog.cpp
        cf/beagraph.cpp
        cf/birds.cpp
        cf/blackboard.cpp
        cf/breakdoor.cpp
        cf/circularrmq.cpp
        cf/coffeecourse.cpp
        cf/costree.cpp
        cf/coverp.cpp
        cf/createsnap.cpp
        cf/date.cpp
        cf/destorycol.cpp
        cf/elongmat.cpp
        cf/fairnut.cpp
        cf/imbarr.cpp
        cf/invexp.cpp
        cf/karensupermarket.cpp
        cf/kcolor.cpp
        cf/kquery.cpp
        cf/monore.cpp
        cf/moonlight.cpp
        cf/mstuni.cpp
        cf/presuf.cpp
        cf/randomtask.cpp
        cf/roundsub.cpp
        cf/seqdiv.cpp
        cf/serenbrac.cpp
        cf/strmul.cpp
        cf/vasyarobot.cpp
        cf/vasyatree.cpp
        cf/vovawall1.cpp
        cf/waterbuy.cpp
        cf/yabp.cpp
        cf/buylunch.cpp
        cf/draw.cpp
        cf/knighttournament.cpp
        cf/manhole.cpp
        cf/matrice.cpp
        cf/nastyabook.cpp
        cf/nastyalegend.cpp
        cf/treasure.cpp
        cf/xeniabit.cpp
        contests/art2/art2.cpp
        contests/balance/balance.cpp
        contests/barnpainting/barnpainting.cpp
        contests/bphoto/bphoto.cpp
        contests/checklist/checklist.cpp
        contests/cownav/cownav.cpp
        contests/cownomics/cownomics.cpp
        contests/cowpatibility/cowpatibility.cpp
        contests/dining/dining.cpp
        contests/feb19_plat/cowdate.cpp
        contests/feb19_plat/mooriokart.cpp
        contests/feb19_plat/mooriokart2.cpp
        contests/feb19_plat/mowing.cpp
        contests/greedy/greedy.cpp
        contests/moocast/moocast.cpp
        contests/piepie/piepie.cpp
        contests/poetry/poetry.cpp
        contests/redistricting/redistricting.cpp
        contests/redistricting/redistricting2.cpp
        contests/redistricting/redistricting3.cpp
        contests/sleepy/sleepy.cpp
        contests/slingshot/slingshot.cpp
        contests/sort/sort.cpp
        contests/talent/talent.cpp
        contests/teamwork/teamwork.cpp
        contests/tracking2/tracking2.cpp
        hpi2019/A.cpp
        hpi2019/B.cpp
        hpi2019/C.cpp
        hpi2019/D.cpp
        hpi2019/E.cpp
        hpi2019/F.cpp
        hpi2019/G.cpp
        hpi2019/H.cpp
        hpi2019/I.cpp
        hpi2019/I2.cpp
        hpi2019/J.cpp
        hpi2019/L.cpp
        hpi2019/template.cpp
        template/fastscan.cpp
        template/segtree.cpp
        train/agrinet/agrinet.cpp
        train/ariprog/ariprog.cpp
        train/barn1/barn1.cpp
        train/butter/butter.cpp
        train/camelot/camelot.cpp
        train/castle/castle.cpp
        train/combo/combo.cpp
        train/comehome/comehome.cpp
        train/concom/concom.cpp
        train/contact/contact.cpp
        train/cowtour/cowtour.cpp
        train/crypt1/crypt1.cpp
        train/dualpal/dualpal.cpp
        train/fact4/fact4.cpp
        train/fence/fence.cpp
        train/fence9/fence9.cpp
        train/frac1/frac1.cpp
        train/fracdec/fracdec.cpp
        train/game1/game1.cpp
        train/hamming/hamming.cpp
        train/heritage/heritage.cpp
        train/holstein/holstein.cpp
        train/humble/humble.cpp
        train/humble/humble2.cpp
        train/inflate/inflate.cpp
        train/kimbits/kimbits.cpp
        train/lamps/lamps.cpp
        train/maze1/maze1.cpp
        train/milk/milk.cpp
        train/milk3/milk3.cpp
        train/money/money.cpp
        train/msquare/msquare.cpp
        train/namenum/namenum.cpp
        train/nocows/nocows.cpp
        train/nuggets/nugget.cpp
        train/numtri/numtri.cpp
        train/palsquare/palsquare.cpp
        train/pharmacy/pharmacy.cpp
        train/pprime/pprime.cpp
        train/preface/preface.cpp
        train/prefix/prefix.cpp
        train/range/range.cpp
        train/ratios/ratios.cpp
        train/ratios/ratios2.cpp
        train/rockers/rockers.cpp
        train/runround/runround.cpp
        train/shopping/shopping.cpp
        train/skidesign/skidesign.cpp
        train/sort3/sort3.cpp
        train/spin/spin.cpp
        train/sprime/sprime.cpp
        train/stamps/stamps.cpp
        train/subset/subset.cpp
        train/transform/transform.cpp
        train/ttwo/ttwo.cpp
        train/wormhole/wormhole.cpp
        train/zerosum/zerosum.cpp cf/importantfiles.cpp cf/zeroarray.cpp cf/maxmedian.cpp)

add_executable(draw cf/draw.cpp)
add_executable(treasure cf/treasure.cpp)
add_executable(palindromeless cf/palindromeless.cpp)
add_executable(mintriangle cf/mintriangle.cpp)
add_executable(redistricting4 contests/redistricting/redistricting4.cpp)
add_executable(stall4 train/stall4.cpp)
add_executable(asyaarray cf/asyaarray.cpp)
add_executable(asyakittens cf/asyakittens.cpp)
add_executable(arrayrestore cf/arrayrestore.cpp)
add_executable(getrekt misc/getrekt.cpp)
add_executable(valleys contests/valleys.cpp)
add_executable(treeboxes contests/treeboxes.cpp)
add_executable(alien codejam2019/round1a/alien.cpp)
add_executable(pylons codejam2019/round1a/pylons.cpp)
add_executable(gopher codejam2019/round1a/gopher.cpp)
add_executable(pylontester codejam2019/round1a/pylontester.cpp)
add_executable(pylon2 codejam2019/round1a/pylon2.cpp)
add_executable(actg cf/actg.cpp)
add_executable(badxor cf/badxor.cpp)
add_executable(queuebuffet cf/queuebuffet.cpp)
add_executable(problemfornazar cf/problemfornazar.cpp)
add_executable(newelements2 codejam2019/round2/newelements2.cpp)
add_executable(newelements1 codejam2019/round2/newelements1.cpp)
add_executable(pottery codejam2019/round2/pottery.cpp)
add_executable(importantfiles cf/importantfiles.cpp)
add_executable(zeroarray cf/zeroarray.cpp)
add_executable(maxmedian cf/maxmedian.cpp)
add_executable(A astar/turing/UCF/A.cpp)
add_executable(B astar/turing/UCF/B.cpp)
add_executable(C astar/turing/UCF/C.cpp)
add_executable(D astar/turing/UCF/D.cpp)
add_executable(F astar/turing/UCF/F.cpp)
add_executable(E astar/turing/UCF/E.cpp)
add_executable(buckets astar/turing/buckets.cpp)
add_executable(p11212 newLowerBoundProblems/p11212.cpp)
add_executable(p256 newLowerBoundProblems/p256.cpp)
add_executable(p927 newLowerBoundProblems/p927.cpp)
add_executable(p10125 newLowerBoundProblems/p10125.cpp)
add_executable(p750 newLowerBoundProblems/p750.cpp)
add_executable(p11157 newLowerBoundProblems/p11157.cpp)
add_executable(p193 newLowerBoundProblems/p193.cpp)
add_executable(p10341 newLowerBoundProblems/p10341.cpp)
add_executable(p507 newLowerBoundProblems/p507.cpp)
add_executable(p836 newLowerBoundProblems/p836.cpp)
add_executable(p10827 newLowerBoundProblems/p10827.cpp)
add_executable(p-1 misc/p-1.cpp)
add_executable(p+1 misc/p+1.cpp)
add_executable(bessieball astar/turing/bessieball.cpp)
add_executable(usamts2019R2P4 astar/turing/UCF/usamts2019R2P4.cpp)

add_executable(BB UCF/BB.cpp)
add_executable(room UCF/room.cpp)
add_executable(treedepth contests/treedepth.cpp)
add_executable(snowcow contests/snowcow.cpp)
add_executable(treedepth2 contests/treedepth2.cpp)
add_executable(cave contests/cave.cpp)
add_executable(nondec contests/nondec.cpp)
add_executable(falling contests/falling.cpp)