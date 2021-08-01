package main

import (
	"flag"
	"fmt"
	"io/ioutil"
	"os"
	"path"
)

type DelPaths []string

func (it *DelPaths) String() string {
	return "list of path for removing"
}

func (it *DelPaths) Set(value string) error {
	if len(value) == 0 {
		return fmt.Errorf("you can't set nothing!")
	}
	*it = append(*it, value)
	return nil
}

var delPaths DelPaths

func main() {
	flag.Var(&delPaths, "path", "remove this path")
	flag.Parse()
	if len(delPaths) == 0 {
		fmt.Println("I can't delete nothing!")
		return
	}
	for _, it := range delPaths {
		_, err := os.Stat(it)
		if err != nil {
			continue
		}
		err = remoteIt(it)
		if err != nil {
			fmt.Println(err)
		}
	}
}

func remoteIt(target string) error {
	dir, err := ioutil.ReadDir(target)
	if err != nil {
		return err
	}
	for _, d := range dir {
		os.RemoveAll(path.Join([]string{target, d.Name()}...))
	}
	return os.RemoveAll(target)
}
