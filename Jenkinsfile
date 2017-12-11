pipeline {
  agent any
  stages {
    stage('GitHub clone') {
      steps {
        git(url: 'https://github.com/ejxct/92-spoons-ai/', branch: 'master')
      }
    }
    stage('Mac Build') {
      parallel {
        stage('Mac Build') {
          steps {
            sh 'mkdir release-mac && clang++ -std=c++11 ai.cpp -o release-mac/ai && zip -r release-mac.zip release-mac'
          }
        }
        stage('Windows Build') {
          steps {
            sh 'mkdir release-win && usr/local/gcc-4.8.0-qt-4.8.4-for-mingw32/win32-gcc/bin/i586-mingw32-g++ -std=c++11 ai.cpp -o release-win/ai && zip -r release-win.zip release-win'
          }
        }
      }
    }
    stage('GitHub Releases') {
      steps {
        sh '/Users/grant/go/bin/github-release release --draft -u ejxct -r 92-spoons-ai -t $BUILD_NUMBER -s "a8230c92850b0cad68a""dcfd146ab0201d307d4c3" && /Users/grant/go/bin/github-release upload -u ejxct -r 92-spoons-ai -n mac-release.zip --file release-mac.zip -s "a8230c92850b0cad68adcf""d146ab0201d307d4c3" -t $BUILD_NUMBER'
      }
    }
    stage('After-build') {
      steps {
        archiveArtifacts '*'
        emailext(subject: '$DEFAULT_SUBJECT', body: '$DEFAULT_CONTENT', attachLog: true, replyTo: '$DEFAULT_REPLYTO', to: '$DEFAULT_RECIPIENTS')
        cleanWs(cleanWhenAborted: true, cleanWhenFailure: true, cleanWhenNotBuilt: true, cleanWhenSuccess: true, cleanWhenUnstable: true, deleteDirs: true, cleanupMatrixParent: true)
      }
    }
  }
}